import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class sfz{
    public static void main(String args[]){
        System.out.print("请输入身份证号:");
        Scanner sc = new Scanner(System.in);
        String sfz = sc.next();
        check sfz_check = new check();
        System.out.println((sfz_check.check(sfz))?"身份证校验正确":"身份证校验失败");
    }
}

class check{
    public boolean check(String id){
        return (this.birthday(id) == 0 && this.len(id) == 0)?true:false;
    }

    public int len(String id){
        //id.substring(0,endIndex)
        return (id.length() == 18)?0:-1;
    }

    public int birthday(String id){
        int year = Integer.parseInt(id.substring(6,10));
        int month = Integer.parseInt(id.substring(10,12));
        int day = Integer.parseInt(id.substring(12,14));
        //System.out.println(year);
        //System.out.println(month);
        //System.out.println(day);
        //String birth = id.substring(6,14);
        //Long now = new Date().getTime();
        Date d = new Date();
        Calendar cal = Calendar.getInstance();
        cal.setTime(d);
        int now_year = cal.get(Calendar.YEAR);
        //int now_month = Calendar.getInstance().get(Calendar.DAY_OF_MONTH);
        //int now_day = Calendar.getInstance().get(Calendar.DATE);
        int age = now_year - year;
        int month_day = (month%2 == 0)?31:30;
        
        if(age > 100 || age < 0){
            return -1;
        }else if(month > 12 || month < 0){
            return -1;
        }else if(month == 2 && day > 28){
            return -1;
        }else if(month > 6 && 9 > month && month_day > 31){//7,8月
            return -1;
        }else if(day > month_day){
            return -1;
        }
        return 0;
    }
}