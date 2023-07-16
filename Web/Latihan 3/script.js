var selectDay = document.getElementById("tgl_lahir");
var selectMonth = document.getElementById("bln_lahir");
var selectYear = document.getElementById("thn_lahir");

document.addEventListener("DOMContentLoaded", function() {
    var selectYear = document.getElementById("thn_lahir");
    for (var i = 1940; i <= 2018; i++) {
      var option = document.createElement("option");
      option.value = i;
      option.text = i;
      selectYear.add(option);
    }

    selectMonth.addEventListener("change", updateDays);
    selectYear.addEventListener("change", updateDays);
    updateDays();
});

function updateDays() {
  var month = selectMonth.value;
  var year = selectYear.value;

  selectDay.innerHTML = '<option selected disabled>Tanggal</option>';

  var daysInMonth = new Date(year, month, 0).getDate();

  for (var i = 1; i <= daysInMonth; i++) {
    var option = document.createElement("option");
    option.value = i;
    option.text = i;
    selectDay.add(option);
  }
}