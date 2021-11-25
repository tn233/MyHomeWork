import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

//删除目录，包括其中的子目录

public class delete{
    public static void main(String[] args) {
        //deleteAll("/Users/tn233/Desktop");
        copyFile("/Users/tn233/Desktop/1.jpg","/Users/tn233/Desktop/2.jpg");
    }

    //
    public static boolean deleteAll(String path){
        File f = new File(path);
        //它不存在
        if(f.exists() == false){
            return false;
        }

        for(String c : f.list()){
            File fs = new File(path + "/" + c);
            if(fs.isFile() == true){//如果是文件
                //这只是一个例子，正式环境，下面的一行切勿去掉注释
                //fs.delete();//删除当前文件夹，配合递归思想
                //System.out.println(path + "/" + c);
            }else{//文件夹
                deleteAll(path + "/" + c);//递归思想删除子文件和文件夹
                //这只是一个例子，正式环境，下面的一行切勿去掉注释
                //fs.delete();//删除当前文件夹，配合递归思想
            }
            //System.out.println(c);
        }
        return true;
    }

    public static boolean copyFile(String source,String target){
        try{
            FileInputStream sf = new FileInputStream(source);
            byte context[] = sf.readAllBytes();
            FileOutputStream ts = new FileOutputStream(target);
            ts.write(context);
            sf.close();
            ts.close();
            return true;
        }catch(Exception e){
            System.out.println(e);
            return false;
        }
    }
}