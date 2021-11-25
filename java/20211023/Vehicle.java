public class Vehicle {
    int wheels;
    double weights;
    Vehicle(int wheels,double weights){
        this.wheels=wheels;
        this.weights=weights;
    }
    void disMessage(){
        System.out.println("这个车车轮个数是"+wheels+"重量是"+weights+"斤");
    }
    public static void main(String args[]){
        Vehicle v = new Vehicle(8,10.00);
        smallCar c = new smallCar(6);
        Truck t = new Truck(10);
        v.disMessage();
        c.disM();
        t.disM2();
        t.disM3();
    }
}

    class smallCar extends Vehicle{
        int loader;
    
        smallCar(int loader){
            super(16,20.00);
            this.loader = loader;
        }
        void disM(){
            System.out.println("这个小汽车可载"+loader+"人");
        }
    }
    
    class Truck extends smallCar{
        int payload;
        Truck(int payload){
            super(6);
            this.payload = payload;
        }

        void disM2(){
            System.out.println("这卡车载重为"+payload+"kg");
        }

        void disM3(){
            System.out.println("这卡车有"+wheels+"个轮子"+"车重有"+weights+"斤"+"可载"+loader+"人"+"载重为"+payload+"斤");
        }
        
    }




    
