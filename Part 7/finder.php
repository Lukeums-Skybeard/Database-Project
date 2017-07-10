<!-- -*-html-*- -->
<!DOCTYPE html>
<html lang="en-US">

<head>
    <title>Fantastic Furniture</title>
    <style>
        table {
            border-collapse: collapse;
        }

        table,
        th,
        td {
            border: 1px solid gray;
        }

	img {
	    max-width: 100%;
	    height: auto;
	}
    </style>
    <?php
	// copied with gratitude from http://stackoverflow.com/a/619725/1133298
	function endswith($string, $test) {
	    $strlen = strlen($string);
	    $testlen = strlen($test);
	    if ($testlen > $strlen) return false;
	    return substr_compare($string, $test, $strlen - $testlen, $testlen) === 0;
	}
    ?>
</head>

<body>

    <?php
require 'conn.php';
$searchText = $_POST["searchText"];
$result  = $conn->prepare("SELECT * FROM (SELECT DISTINCT * FROM Model M join describes D using (modelNumber) join Item I using (sku) where M.name_ LIKE :searchText1 OR M.material LIKE :searchText2 OR M.upholstery LIKE :searchText3 OR M.durability LIKE :searchText4 OR M.color LIKE :searchText5 OR I.condition_ LIKE  :searchText6) R ORDER BY R.modelNumber, R.sku;");
$result->bindValue(":searchText1", "%{$searchText}%", PDO::PARAM_STR);
$result->bindValue(":searchText2", "%{$searchText}%", PDO::PARAM_STR);
$result->bindValue(":searchText3", "%{$searchText}%", PDO::PARAM_STR);
$result->bindValue(":searchText4", "%{$searchText}%", PDO::PARAM_STR);
$result->bindValue(":searchText5", "%{$searchText}%", PDO::PARAM_STR);
$result->bindValue(":searchText6", "%{$searchText}%", PDO::PARAM_STR);
$result->execute();
$numCols = $result->columnCount();

echo "<table><thead><tr><th>Image</th>";
for ($colNum = 0; $colNum < $numCols; $colNum++) {
    $colMeta = $result->getColumnMeta($colNum);
    echo "<th><code>" . $colMeta["name"] . "</code> [<code>" . $colMeta["native_type"] . "</code>]</th>";
}
echo "</tr></thead><tbody>";
foreach ($result->fetchAll() as $resultRow) {
    if (endswith($resultRow["name_"], "Chair")) {
	$imageTag = '<img src="chair.png" alt="Chair">';
    } else if (endswith($resultRow["name_"], "Cabinet")) {
	$imageTag = '<img src="cabinet.png" alt="Cabinet">';
    } else if (endswith($resultRow["name_"], "Desk")) {
	$imageTag = '<img src="desk.png" alt="Desk">';
    } else if (endswith($resultRow["name_"], "Bedframe")) {
	$imageTag = '<img src="bedframe.png" alt="Bedframe">';
    } else if (endswith($resultRow["name_"], "Stool")) {
	$imageTag = '<img src="stool.png" alt="Stool">';
    } else if (endswith($resultRow["name_"], "Table")) {
	$imageTag = '<img src="table.png" alt="Table">';
    } else {
	$imageTag = "";
    }
    echo "<tr><td>" . $imageTag . "</td>";
    for ($colNum = 0; $colNum < $numCols; $colNum++) {
        echo "<td>" . $resultRow[$colNum] . "</td>";
    }
    echo "</tr>";
}
echo "</tbody></table>";

$result->closeCursor();
$result = null;
$conn   = null;
	    ?>

</body>

</html>
