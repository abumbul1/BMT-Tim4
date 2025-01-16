<?php
// Podešavanje podataka za konekciju sa bazom
$servername = "localhost";   // Server baze (ako je lokalni server, koristi localhost)
$username = "root";          // Korisničko ime za bazu
$password = "";              // Lozinka za bazu (ako je prazna, ostavi tako)
$dbname = "tim4";      // Ime tvoje baze podataka


// Kreiranje konekcije
$conn = new mysqli($servername, $username, $password, $dbname);


// Provjera konekcije
if ($conn->connect_error) {
  die("Konekcija nije uspela: " . $conn->connect_error);
}


// Preuzimanje podataka iz GET zahteva
$temperatura = $_GET['temperatura'];
$vlaga = $_GET['vlaga'];


// Unos podataka u MySQL tabelu
$sql = "INSERT INTO podaci (temperatura, vlaga) VALUES ($temperatura, $vlaga)";


// Provjeri da li je unos uspješan
if ($conn->query($sql) === TRUE) {
  echo "Podaci su uspješno unijeti u bazu.";
} else {
  echo "Greška: " . $sql . "<br>" . $conn->error;
}


// Zatvori konekciju
$conn->close();
?>
