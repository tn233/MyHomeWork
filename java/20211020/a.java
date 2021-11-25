import java.util.Random;

public class a{
    public static void main(String[] args){
        int order = 1;
        student[] arr = new student[70];
        int a = 0;
        Random r = new Random(36);
        for(;a<70;a++){
            arr[a] = new student();
            arr[a].no = order++;
            arr[a].score = r.nextInt(101);
        }

        student tmp;
        for(int i = 0;i<(arr.length - 1);i++){
            for(int j = 0;j<(arr.length - 1 - i);j++){
                if(arr[j].score < arr[j+1].score){
                    tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }

        for(int c = 0;c<70;c++){
            System.out.println("学生编号:"+arr[c].no+"学生成绩:"+arr[c].score);
        }


        int max = 0,min = 100,total = 0;
        for(int s = 0;s<arr.length;s++){
            if(arr[s].score > max){
                max = arr[s].score;
            }else if(arr[s].score < min){
                min = arr[s].score;
            }
            total += arr[s].score;
        }
        System.out.println("最高分:"+max+"最低分:"+min+"平均分:"+(total/70));

    }
}

class student{
    int no;
    int score;
}