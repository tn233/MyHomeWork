public class test {
    public static void main(String[] args) {
        try{
            int a = 10/0;
            System.out.println("try");
        }catch(Exception e){
            System.out.println("catch");
        }
    }
}
