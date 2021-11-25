public class Lib{
    // 创建一个图书类，类中包含的属性有：书名、作者、出版社；包含的方法有：设置书籍状// 态，查看书籍状态。书籍状态有在馆和外借两种。 
    
    private String Bname; 
    private String Aname; 
    private String Baddress; 
    //书籍状态 
    private boolean zt;
    //包含方法 set get 
    public void setzt(boolean zt){ 
        this.zt = zt; 
    }
    
    public boolean getzt(){ 
        return this.zt;
    }

    public void setAname(String aname) {
        Aname = aname;
    }

    public String getAname() {
        return Aname;
    }

    public void setBaddress(String baddress) {
        Baddress = baddress;
    }

    public String getBaddress() {
        return Baddress;
    }

    public void setBname(String bname) {
        Bname = bname;
    }

    public String getBname() {
        return Bname;
    }

    public static void main(String[] args){ 
        Lib book = new Lib();
        //编写了其余的get和set方法
        book.setAname("汪沁");
        book.setBaddress("清华大学出版社");
        book.setBname("数据结构");
        book.setzt(true);
        System.out.println("书名:"+book.getBname());
        System.out.println("出版社:"+book.getBaddress());
        System.out.println("作者:"+book.getAname());
        System.out.println("状态:"+(book.getzt() == false?"外借":"在馆"));
    } 
}