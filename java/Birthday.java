public class Birthday{ 
        //设计一个 Birthday 类，其成员变量有：year,month,day；提供构造方法、输出 Birthday 对象值的方法和 计算年龄的方法。编写程序测试这个类。 
        private int year; 
        private int month; 
        private int day;
        
        public Birthday(int year,int month,int day){ 
            this.year = year; 
            this.month = month; 
            this.day = day;
        } 
    
    public void printBirthDay(){ 
        System.out.println("生日:"+year+"-"+month+"-"+day); 
    }
    
    public int printAge(){
        return 2021 - year; 
    }
    
    public static void main(String[] args){ 
        Birthday birth = new Birthday(2002, 6, 19);
        birth.printBirthDay();
        System.out.println("年龄:"+birth.printAge());
    }
}
