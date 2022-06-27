// SPDX-License-Identifier: MIT
pragma solidity >=0.4.25 <0.7.0;

// This is just a simple example of a coin-like contract.
// It is not standards compatible and cannot be expected to talk to other
// coin/token contracts. If you want to create a standards-compliant
// token, see: https://github.com/ConsenSys/Tokens. Cheers!

contract MetaCoin {
    
	mapping (address => uint256) balances;
	event Transfer(address indexed _from, address indexed _to, uint256 _value);

	constructor() public {
		balances[tx.origin] = 100000;
	}

	function sendCoin(address receiver, uint256 amount, address sender) public returns(bool sufficient) {
		if (balances[sender] < amount) return false;
		balances[sender] -= amount;
		balances[receiver] += amount;
		emit Transfer(sender, receiver, amount);
		return true;
	}


	function getBalance(address addr) public view returns(uint256) {
		return balances[addr];
	}
}


contract Loan is MetaCoin {
 
    mapping (address => uint256) private loans;
     
    event Request(address indexed _from, uint256 P, uint R, uint T, uint256 amt);
    event OwnerSet(address indexed oldOwner, address indexed newOwner);
    
    address public Owner;
    //a modifier to allow only the owner of the contract to use specific functions
    modifier isOwner() {
       require(msg.sender == Owner);
        _;
    }
    
    // Making the creator of the contract the Owner.
    constructor() public {
        Owner = msg.sender; // 'msg.sender' is sender of current call, contract deployer for a constructor
        emit OwnerSet(address(0), Owner);
    }
    
     //function to calculate compound intrest 
    function getCompoundInterest(uint256 principle, uint rate, uint time) public pure returns(uint256){
         for(uint i=0;i<time;i++){
         principle = addmod(principle ,((principle*rate)/100),(2**255));
         }
         return principle;
    }


    function reqLoan(uint256 principle, uint rate, uint time) public returns(bool) {
        uint256 toPay = getCompoundInterest(principle, rate, time);
        // A creditor uses this function to request the Owner to settle his loan,
        //and the amount to settle is calculated using the inputs.
        address creditor=msg.sender;
        loans[creditor]=toPay;
        //emit the Request event after succesfully adding to the mapping
        emit OwnerSet(address(0),creditor);

        if(loans[creditor]!=0){
            return true;
        }
        else{
            return false;
        }
         
    }
    
    function getOwnerBalance() public view returns(uint256) {
        // view the Balance of the contract Owner
                return getBalance(Owner);
		}
    
      // viewDues which allow *ONLY* the owner to *view* his loans
    function viewDues(address creditor) public view isOwner returns(uint256){
              return loans[creditor];
    } 
    
      //settleDues which allow *ONLY* the owner to *settle* his loans
      //I returns a bool, true if the dues were settled and false otherwise.
    function settleDues(address creditor) public isOwner returns (bool){
        sendCoin(Owner, loans[creditor], creditor);
        if(sendCoin(Owner, loans[creditor], creditor)){
            loans[creditor] = 0;
        }
        if(loans[creditor] == 0){
            return true;
        }
        else{
        return false;
        }
    }

}
