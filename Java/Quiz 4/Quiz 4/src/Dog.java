public class Dog {
    private int size;
    private String name;
    private boolean hit;
    public Dog(int s, String n) {
        this.size = s;
        this.name = n;
        this.hit = false;
    }

    public void setSize(int s) {
        this.size = s;
    }

    public int getSize() {
        return this.size;
    }

    public void setName(String n) {
        this.name = n;
    }

    public String getName() {
        return this.name;
    }

    public void setHitStatus(boolean bool) {
        this.hit = bool;
    }

    public boolean getHitStatus() {
        return this.hit;
    }

    public void bark() {
        System.out.println(toString());
    }

    public String toString() {
        String str = "I'm " + this.name + ", Size:" + this.size + ", ";
        if (this.size > 60) {
            str = str + "Wooof! Wooof!";
        } else if (this.size > 14) {
            str = str + "Ruff! Ruff!";
        } else {
            str = str + "Yip! Yip!";
        }
        return str;
    }
}
