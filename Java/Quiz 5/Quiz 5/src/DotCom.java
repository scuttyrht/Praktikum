import java.util.ArrayList;

public class DotCom {
    private ArrayList<String> locs;
    private String name;

    public void setLocs(ArrayList<String> arrList) {
        this.locs = arrList;
    }

    public ArrayList<String> getLocs() {
        return locs;
    }

    public void setName(String n) {
        this.name = n;
    }

    public String checkYourself(String input) {
        String str = "miss";
        int i = this.locs.indexOf(input);
        if (i >= 0) {
            this.locs.remove(i);
            if (this.locs.isEmpty()) {
                str = "kill";
                System.out.println("Ouch! You sunk " + this.name + " : ( ");
            } else {
                str = "hit";
            }
        }
        return str;
    }
}
