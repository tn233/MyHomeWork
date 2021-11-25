class Car{
    String chePai;
    float price;
    float price1;
    
    Car(String chePai,float price){
        this.chePai=chePai;
        this.price1=price*4/5;
        this.price=price;
    }

    void dismessage(){
        System.out.println("这辆车的品牌是"+chePai+"原价是"+price+"打折后为"+price1);
    }

    int change(float price){//修改折扣后的售价
        this.price1 = price;
        return 0;
    }

    int change_by_off(double off){
        this.price1 = (float) (price * off);
        return 0;
    }
}
    
    public class TestCar{
        public static void main(String[] args){
            Car c = new Car("奔驰 S6OO",50000);
            c.dismessage();
            c.change(47827);
            c.dismessage();
            c.change_by_off(0.5);
            c.dismessage();
        }
    }