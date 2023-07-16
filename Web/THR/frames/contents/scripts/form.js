// Kita ambil value dari setiap elemen
var username = document.getElementsById("uname").value;
var password = document.getElementById("pw").value;
var fullname = document.getElementById("fname").value;
var tmpt_lahir = document.getElementById("tmpt_lhr").value;
var tgl_lahir = document.getElementById("tgl_lhr").value;
var bln_lahir = document.getElementById("bln_lhr").value;
var thn_lahir = document.getElementById("thn_lhr").value;
var no_hp = document.getElementById("no_hp").value;
var email_name = document.getElementById("email_name").value;
var email_suffix = document.getElementById("email_suffix").value;
var jk = document.getElementById("jk").value;
var agama = document.getElementById("agm").value;
var hobi = document.getElementById("hobi").checked; // Untuk checkbox menggunakan `.checked`
var selectDay = document.getElementById("tgl_lhr");
var selectMonth = document.getElementById("bln_lhr");
var selectYear = document.getElementById("thn_lhr");

// Event Listener untuk mengganti list tanggal dalam tanggal lahir
document.addEventListener("DOMContentLoaded", function() {
    var selectYear = document.getElementById("thn_lhr");
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

// Fungsi untuk validasi form
function validateForm() {
    if (username === '') {
        alert('Pastikan username diisi');
        return false;
    }
    
    if (password === '') {
        alert('Pastikan password diisi');
        return false;
    }

    // Validasi length password agar hanya diantara 6-20
    if (password.length < 6 || password.length > 20) {
        alert('Pastikan password berisi 6-20 karakter');
        return false;
    }
    
    if (fullname === '') {
        alert('Pastikan nama lengkap diisi');
        return false;
    }
  
    if (tmpt_lahir === '') {
        alert('Pastikan tempat lahir diisi');
        return false;
    }
  
    if (tgl_lahir === '' || bln_lahir === '' || thn_lahir === '') {
        alert('Pastikan tanggal lahir lengkap');
        return false;
    }
      
    if (no_hp === '') {
        alert('Pastikan nomor Hp diisi');
        return false;
    }

    // Validasi untuk memastikan input hanya berisi nomor
    if (/^\d+$/.test(no_hp) === false) {
        alert('Pastikan nomor Hp hanya berisi angka');
        return false;
    }
  
    if (phoneNumber.length != 11){
        alert('Nomor Hp invalid');
        return false;
    }
  
    if (email_name === '' || email_suffix === '') {
        alert('Pastikan email lengkap');
        return false;
    }
      
    if (jk === '') {
        alert('Pastikan jenis kelamin terpilih');
        return false;
    }
  
    if (agama === '') {
        alert('Pastikan agama terpilih');
        return false;
    }
      
    if (hobbies === false) {
        alert('Apabila hobi tidak tersedia dalam list, mohon pilihlah "Lain"');
        return false;
    }
      
    // Submit form apabila semua sudah terpenuhi
    return true;
}