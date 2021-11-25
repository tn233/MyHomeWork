import java.util.Scanner;

public class Money{
    public static void main(String[] arg){
        System.out.print("输入单额:");
        Scanner input = new Scanner(System.in);
        int point = input.nextInt()/10000;
        int base = 1750;
        switch(point){
            case 0:
            System.out.print("0%");
            break;
            case 1:
            case 2:
            System.out.print("5%");
            break;
            case 3:
            case 4:
            case 5:
            System.out.print("8%");   
            break;
            case 6:
            case 7:
            case 8:
            case 9:
            System.out.print("10%");
            break;
            default://代表大于10w以及以上的结果
            System.out.print("12%");
        }
    }
}