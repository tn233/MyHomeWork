package bank;

import java.util.*;
class BankCount{

    int id;
    String name,date;
    float money;

    public BankCount(int id,String name,String date,float money){
        this.id=id;
        this.name=name;
        this.date=date;
        this.money=money;
    }

}

class BCOption {
    Vector vec = new Vector();
    static int count = 0;

    public void kaihu(BankCount bc){
        count++;
        vec.add(bc);
    }

    public void moneyOut(int id,float outmoney){
        BankCount bc = (BankCount)vec.get(id);
        bc.money -= outmoney;
        vec.set(id,bc);
    }
        
    public void moneyln(int id,float inmoney){
        BankCount bc = (BankCount)vec.get(id);
        bc.money += inmoney;
        vec.set(id,bc);
    }

    public void query(int id){
        BankCount bc = (BankCount)vec.get(id);
        System.out.println(bc.id+" "+bc.name+" "+bc.date+" "+bc.money);
    }

    public void transfer(BankCount accountOut,BankCount acountIn,float money){
        System.out.println("转账信息:\n转账人:"+accountOut.name+"\n收款人:"+acountIn.name+"\n转账金额:"+money+"元");
        this.moneyOut(accountOut.id,money);
        this.moneyln(acountIn.id,money);
    }

    public static void Main(String args[]){
        BCOption bco = new BCOption();
        BankCount user1 = new BankCount(0,"小张","20020101",13);
        BankCount user2 = new BankCount(1,"小王","20080815",12);
        bco.kaihu(user1);
        bco.kaihu(user2);
        bco.query(0);
        bco.query(1);
        System.out.println("");
        bco.transfer(user1,user2,2);
        System.out.println("");
        bco.query(0);
        bco.query(1);
    }
}
