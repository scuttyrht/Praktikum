import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class DateTime {
    public static String getCurrentDateTime() {
        LocalDateTime localDateTime = LocalDateTime.now();
        return localDateTime.format(DateTimeFormatter.ofPattern("dd-MM-yyyy hh:mm:ss"));
    }

    public static void countAge() {
        String str = null;
        try {
            LocalDate localDate = LocalDate.now();
            DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            String input;
            AppHelper aF = new AppHelper();
            input = aF.getInput("Masukkan Tanggal Lahir Anda (dd/mm/yyyy): ");
            if (splitString(input)) {
                LocalDate localDate1 = LocalDate.parse(input, dateTimeFormatter);
                Period period = Period.between(localDate1, localDate);
                str = "Usia Anda: " + localDate.getYear() + " Tahun " + period.getYears() + " Bulan " + period.getMonths() + " Hari";
            }
        } catch (DateTimeParseException dateTimeParseException) {

        } catch (Exception exception) {}
        System.out.println(str);
    }

    public static boolean splitString(String paramString) {
        boolean bool = true;
        if (paramString.length() != 10)
            bool = false;
        String[] splitString = paramString.split("/");
        if (splitString.length == 3) {
            try {
                Integer.parseInt(splitString[0]);
                Integer.parseInt(splitString[1]);
                Integer.parseInt(splitString[2]);
            } catch (Exception exception) {
                bool = false;
            }
        } else {
            bool = false;
        }
        return bool;
    }
}
