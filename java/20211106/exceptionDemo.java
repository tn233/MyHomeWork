import java.util.Scanner;

class 负分异常 extends Exception //当录入了负分时。此处应用了自定义异常
{ 
    负分异常(int i){
        System.out.println("分数为负数"); 
    }
}

class 高分异常 extends Exception //当录入分超过100时。应用了自定义异常
{ 
    高分异常(int i){
        System.out.println("分数过高");
    }
} 

public class exceptionDemo{ 
    static final int number = 2; 
    int score[] = new int[number]; 
    //下面方法中判断如果录入的成绩不合理，则抛出异常，
    //但本方法并不处理异常，仅声明了异常
    public void 检查分数(int 分数) throws 负分异常,高分异常{
        if(分数 > 100){
            throw new 高分异常(分数);
        }else if(分数 < 0){
            throw new 负分异常(分数);
        }
        //此处补全代码
    } 

    public void 录入成绩(){
    int i;
    Scanner sc = new Scanner(System.in);
    for(i=0;i<number;i++) { 
        try{
            System.out.print("请输入第"+(i+1) +"个同学的成绩:");
            score[i] = Integer.parseInt(sc.nextLine()); 
        }
        //在try{…….}catch间的语句中若产生异常，
        //则捕获 异常，直接进行异常处理
        catch(NumberFormatException e) {
            throw new NumberFormatException();
        }
        try{
            检查分数(score[i]);
            //在检查分数模块中，可能产生高分异常对象，
            //此处补全代码
            //也可能产生低分异常对象，根据不同情况，进行不同处理 
        }
        catch(高分异常 e){
            System.out.println("A:"+e);
        }catch(负分异常 e){
            System.out.println("A:"+e);
        }
    }
    } 

    public void 输出成绩() {
        System.out.println(score[0]); 
        System.out.println(score[1]);
    } 
    //实现录入数据并输出成绩
    public static void main(String arg[]){
        exceptionDemo demo = new exceptionDemo();
        demo.录入成绩();
        demo.输出成绩();
        //此处补全代码 
    }
}