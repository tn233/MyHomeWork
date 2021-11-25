import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;

//姓名，学号，七门课分数，然后根据格式保存，最后读文件显示

public class scanin{
    public static void main(String[] args) {
        try{
            FileOutputStream fs = new FileOutputStream("student.txt",true);
            while(true){
                Scanner sc = new Scanner(System.in);
                System.out.print("请输入学生姓名:");
                String name = sc.nextLine();
                System.out.print("请输入学生学号:");
                String no = sc.nextLine();
                int i = 1;
                String context = name+"\t"+no+"\t";
                while(i < 8){
                    System.out.print("请输入学生第"+i+"门成绩:");
                    context += sc.nextLine()+"\t";
                    i++;
                }
                context += "\n";
                fs.write(context.getBytes(),0,context.length());
                System.out.print("是否继续录入？(1/0):");
                if(sc.nextInt() == 0){
                    break;
                }
            }
            FileInputStream rs = new FileInputStream("student.txt");
            System.out.print(rs.readAllBytes());
        }catch(Exception e){

        }


    }
}