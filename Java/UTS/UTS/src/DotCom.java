import java.util.ArrayList;

public class DotCom {
    private ArrayList<String> locationCells;

    private String name;

    public void setLocs(ArrayList<String> paramArrayList) {
        this.locationCells = paramArrayList;
    }

    public void setName(String paramString) {
        this.name = paramString;
    }

    public String checkYourself(String paramString) {
        String str = "miss";
        int i = this.locationCells.indexOf(paramString);
        if (i >= 0) {
            this.locationCells.remove(i);
            if (this.locationCells.isEmpty()) {
                str = "kill";
                System.out.println("Ouch! You sunk " + this.name + " : ( ");
            } else {
                str = "hit";
            }
        }
        return str;
    }
}
