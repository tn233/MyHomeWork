public class Test{
    public static void main(String args[]){
        Bank b1 = new Bank("鹿鹿","鹿容","2012-04-30",1,0.0);
        b1.cun(100000.00);
        b1.qu(10000.00);
        b1.info();
    }
}

class Bank{
    private String user;
    private String name;
    private String time;
    private int id;
    private double money;
    Bank(String user,String name,String time,int id,double money){
        this.user = user;
        this.name = name;
        this.time = time;
        this.id =id;
        this.money =money;
    }

    public void cun(double inMoney){
        this.money = this.money + inMoney;
    }

    public void qu(double outMoney){
        if(this.money - outMoney >= 0){
            this.money = this.money - outMoney;
        }
    }

    public void info(){
        System.out.println("余额还有" + this.money);
    }
}

