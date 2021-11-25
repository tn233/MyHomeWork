class Person {
    //定义Person类 
    public int bianhao; 
    public String name; 

    public Person(int biaohao,String name){ 
        this.bianhao = bianhao;
        this.name = name;
    } 
    
    public void input(int bianhao,String name){ 
        this.bianhao=bianhao; 
        this.name=name; 
    } 
    
    public void printXS(){ 
        //定义显示
        System.out.println(bianhao+" "+name); 
    }
    
    public static void main(String[] args) {
        Student s = new Student(1000,"小明",1,70);
        Teacher t = new Teacher(1002,"李梅","讲师","计算机");
        s.printXS();
        t.printXS();
    }
}

    class Student extends Person{
        //定义学生类 
        int banhao;
        int chengji;
        /**
        public Student(){
            super(0,"0");
        }
        **/

        public Student(int bianhao,String name,int banhao,int cj){ 
            super(bianhao,name);
            this.bianhao=bianhao;
            this.name=name; 
            this.banhao=banhao;
            this.chengji=cj; 
        }
    } 

    class Teacher extends Person{ 
        //定义教师类 
        String zhicheng; 
        String bumen;
        /**
        public Teacher(){
            super(0,"0");
        }
        **/
        public Teacher(int bianhao,String name,String zhicheng,String bumen){ 
            super(bianhao,name); 
            this.bianhao=bianhao;
            this.name=name; 
            this.zhicheng=zhicheng; 
            this.bumen=bumen; 
        } 
    }