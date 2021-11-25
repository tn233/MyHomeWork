import java.util.Scanner;

class human{
    public String name;
    public int job;

    public int intro(String name){
        System.out.println("我叫" + name); 
        return 0;
    }
}

class teacher extends human{
    public int intro(String name){
        System.out.print("我是老师,");
        super.intro(name);
        return 0;
    }
}

class student extends human{

    public int intro(String name){
        System.out.print("我是学生,");
        super.intro(name);
        return 0;
    }
}

public class intro {
    public static void main(String args[]){
        human data[] = new human[10];
        Scanner sc = new Scanner(System.in);
        for(int i = 0;i<10;i++){
            data[i] = new human();
            System.out.print("请输入姓名:");
            data[i].name = sc.next();
            System.out.print("是老师还是学生(老师输入1,学生输入2):");
            data[i].job = sc.nextInt();
        }
        sc.close();
        human out = new human();
        for(human s : data){
            if(s.job == 1){
                out = new teacher();
                out.intro(s.name);
            }else if(s.job == 2){
                out = new student();
                out.intro(s.name);
            }
        }
    }
}
