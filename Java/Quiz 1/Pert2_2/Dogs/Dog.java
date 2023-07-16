package Dogs;

public class Dog {
    int size;
    String breed;
    String name;

    public Dog(){
        this("Jack","Puddle",20);
    }
    public Dog(String n, String b, int s){
        name=n;breed=b;size=s;
    }

    public void bark() {
        bark("Ruff! Ruff!");
    }
    public void bark(String b){
        System.out.println(b);
    }
    public String toString(){
        return "Dog name: "+ name + ", size: "+ size +", breed: "+ breed;    
    }
}