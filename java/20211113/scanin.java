import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.Scanner;

//姓名，学号，七门课分数，然后根据格式保存，最后读文件显示

public class scanin{
    public static void main(String[] args) {
        try{
            String context = "";
            FileOutputStream fs = new FileOutputStream("StudentData.txt",true);
            Scanner sc = new Scanner(System.in);
            while(true){
                System.out.print("请输入学生姓名:");
                String name = sc.nextLine();
                context += name + "\t";
                while(true){
                    System.out.print("请输入学生学号:");
                    String input = sc.nextLine();
                    try{
                        Long.parseLong(input.trim());//单纯判断是不是全数,不是exception
                        if(input.substring(0,4).equals("2020") == false || input.length() != 11){
                            System.out.println("学生学号格式错误,请重新输入。");
                            continue;
                        }else{
                            context += input + "\t";
                            break;
                        }
                    }catch(Exception e){
                        System.out.println("学生学号格式错误,请重新输入。");
                        continue;
                    }
                }

                int i = 1;
                while(i < 8){
                    System.out.print("请输入学生第"+i+"门成绩:");
                    int grade = sc.nextInt();
                    if(grade > 100 || grade < 0){
                        System.out.println("学生成绩输入错误,请重新输入。");
                        continue;
                    }else{
                        context += grade + "\t";
                        i++;
                    }
                }
                context += "\n";
                
                System.out.print("是否继续录入？(否请输入0退出):");
                if(sc.nextInt() == 0){
                    break;
                }else{
                    sc.nextLine();
                    continue;
                }
            }
            fs.write(context.getBytes(),0,context.length());
            fs.close();
            System.out.println("姓名\t学号\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\t成绩6\t成绩7\t");
            //Read
            FileReader fileReader = new FileReader("StudentData.txt");
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line = bufferedReader.readLine();
            while (line != null){
                System.out.println(line);
                line = bufferedReader.readLine();
            }
            bufferedReader.close();
            fileReader.close();
        }catch(Exception e){

        }

    }
}