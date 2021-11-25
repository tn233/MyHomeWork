import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileObject{
	String path;
	public FileObject(String path){
	    this.path = path;
    }

//该方法用于删除当前文件或目录，要求能够实现对有子项的目录的删除功能，并返回true或false
public boolean delete(){
    File f = new File(path);
    //它不存在
    if(f.exists() == false){
        return false;
    }

    //他是文件
    if(f.isDirectory() == false){
        f.delete();
        System.out.println("删除文件:" + path);
        return true;
    }

    for(String c : f.list()){
        System.out.println("删除:" + path + "/" + c);
        File fs = new File(path + "/" + c);
        if(fs.isFile() == true){//如果是文件
            //这只是一个例子，正式环境，下面的一行切勿去掉注释
            fs.delete();//删除当前文件夹，配合递归思想
        }else{//文件夹
            delete(path + "/" + c);//递归思想删除子文件和文件夹
            //这只是一个例子，正式环境，下面的一行切勿去掉注释
            fs.delete();//删除当前文件夹，配合递归思想
        }
    }
    //删除根目录
    f.delete();

    return true;
}

//多态
private boolean delete(String TargetPath){
    File f = new File(TargetPath);

    //子文件夹及其文件
    for(String c : f.list()){
        File fs = new File(TargetPath + "/" + c);
        System.out.println("删除:" + TargetPath + "/" + c);
        if(fs.isFile() == true){//如果是文件
            //这只是一个例子，正式环境，下面的一行切勿去掉注释
            fs.delete();//删除当前文件夹，配合递归思想
        }else{//文件夹
            delete(TargetPath + "/" + c);//递归思想删除子文件和文件夹
            //这只是一个例子，正式环境，下面的一行切勿去掉注释
            fs.delete();//删除当前文件夹，配合递归思想
        }
    }
    return true;
}

//该方法用于将当前文件或目录移动到指定位置，如成功完成移动，将新位置保存到path成员变量中，并返回true或false
public boolean moveTo(String TargetPath){
    File f = new File(path);
    //它不存在
    if(f.exists() == false){
        return false;
    }
    //他是文件
    if(f.isDirectory() == false){
        //原本是用于重命名，但此用法可以实现文件移动
        f.renameTo(new File(TargetPath));
        System.out.println("移动文件:" + path + " -> " + TargetPath);
        return true;
    }

    this.path = TargetPath + "/" + f.getName();
    f.renameTo(new File(TargetPath + "/" + f.getName()));
    return true;
}

//该方法用于将当前文件或目录复制到指定位置，如成功完成移动，并返回true或false
public boolean copyTo(String TargetPath){
    File f = new File(path);
    //它不存在
    if(f.exists() == false){
        return false;
    }
    //他是文件
    if(f.isDirectory() == false){
        try{
            FileInputStream sf = new FileInputStream(path);
            //byte context[] = sf.readAllBytes();
            FileOutputStream ts = new FileOutputStream(TargetPath);
            ts.write(sf.readAllBytes());
            sf.close();
            ts.close();
            return true;
        }catch(Exception e){
            System.out.println(e);
            return false;
        }
    }

    //下面都是文件夹

    for(String c : f.list()){
        try{
            System.out.println("复制:" + path + "/" + c + " -> " + TargetPath + "/" + c);
            File fs = new File(path + "/" + c);
            if(fs.isFile() == true){//如果是文件
                try{
                    FileInputStream sf = new FileInputStream(path + "/" + c);
                    FileOutputStream tps = new FileOutputStream(TargetPath + "/" + c);
                    tps.write(sf.readAllBytes());
                    sf.close();
                    tps.close();
                }catch(Exception e){
                    System.out.println(e);
                    return false;
                }
            }else{//文件夹
                File tfs = new File(TargetPath + "/" + c);
                tfs.mkdir();
                copyTo(TargetPath,c);//递归思想移动子文件和文件夹
            } 
        }catch(Exception e){
            System.out.println("复制失败:" + e);
        }
    }

    return true;
}

public boolean copyTo(String TargetPath,String Child){
    File f = new File(path + "/" + Child);
    //它不存在
    if(f.exists() == false){
        return false;
    }
    //他是文件
    if(f.isDirectory() == false){
        try{
            FileInputStream sf = new FileInputStream(path + "/" + Child);
            //byte context[] = sf.readAllBytes();
            FileOutputStream ts = new FileOutputStream(TargetPath + "/" + Child);
            ts.write(sf.readAllBytes());
            sf.close();
            ts.close();
            return true;
        }catch(Exception e){
            System.out.println(e);
            return false;
        }
    }

    //下面都是文件夹

    //对根目录进行创建
    for(String c : f.list()){
        try{
            //获取原文件夹的结构
            File fs = new File(path + "/" + Child + "/" + c);
            System.out.println("复制:" + path + "/" + Child + "/" + c + " -> " + TargetPath  + "/" + Child + "/" + c);
            if(fs.isFile() == true){//如果是文件
                try{
                    FileInputStream sf = new FileInputStream(path + "/" + Child + "/" + c);
                    FileOutputStream tps = new FileOutputStream(TargetPath + "/" + Child + "/" + c);
                    tps.write(sf.readAllBytes());
                    sf.close();
                    tps.close();
                    
                }catch(Exception e){
                    System.out.println(e);
                    return false;
                }
            }else{//文件夹
                File tfs = new File(TargetPath + "/" + Child + "/" + c);
                tfs.mkdir();
                copyTo(TargetPath,Child + "/" + c);//递归思想移动子文件和文件夹
            } 
        }catch(Exception e){
            System.out.println("复制失败:" + e);
        }
    }

    return true;
}

public static void main(String[] args){
    FileObject f = new FileObject("/Users/tn233/Desktop/java/20211120/aaa");
    f.copyTo("/Users/tn233/Desktop/java/20211120/target");
    f.moveTo("/Users/tn233/Desktop/java");
    //f.delete();
	//在主方法中尝试使用所定义的三个方法，分别实现文件移动、复制和删除功能
}
}