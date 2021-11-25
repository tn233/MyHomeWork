class Location{ 
    private int x,y; 
    public Location(int a,int b){
        x = a; y = b;
    }
    
    public int getX(){
        return x;
    } 
    
    public int getY(){
        return y;
    } 
    
    public static void main(String args[]){ 
        Location loc = new Location(12,20); 
        System.out.println(loc.getX()); 
        System.out.println(loc.getY()); 
    }
}