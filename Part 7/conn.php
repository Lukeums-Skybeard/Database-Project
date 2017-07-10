<!-- -*-html-*- -->
<?php 
assert_options(ASSERT_BAIL, 1);
$servername = "localhost";
$dbname     = "aaltman";
require 'info.php';
try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $passwork);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch (PDOException $e) {
    echo "<strong>Error:</strong> " . $e->getMessage();
    die;
}
?>
