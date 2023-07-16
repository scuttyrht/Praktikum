function mobileShowHide() {
    var x = document.getElementById("mobible");
    var y = document.getElementById("mobible-sh-btn");

    if (x.style.display === "none") {
        x.style.display = "block";
    } else {
        x.style.display = "none";
    }

    if (y.innerHTML === "Show") {
        y.innerHTML = "Hide";
    } else {
        y.innerHTML = "Show";
    }
}

function emailShowHide() {
    var x = document.getElementById("email");
    var y = document.getElementById("email-sh-btn");

    if (x.style.display === "none") {
        x.style.display = "block";
    } else {
        x.style.display = "none";
    }

    if (y.innerHTML === "Show") {
        y.innerHTML = "Hide";
    } else {
        y.innerHTML = "Show";
    }
}