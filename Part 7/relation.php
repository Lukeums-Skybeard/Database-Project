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
    </style>
</head>

<body>

    <?php
require 'conn.php';
$validNames   = array(
    "Supplier",
    "Designer",
    "Set_",
    "Model",
    "Item",
    "DistributionCenter",
    "make",
    "contains_",
    "describes",
    "canOrderFrom",
    "Chair",
    "Table_",
    "Desk",
    "Stool",
    "Cabinet",
    "Bedframe",
    "features_Feature"
);
$relationName = $_GET["relation"];
assert(in_array($relationName, $validNames, true), "Invalid relation name!");
$result  = $conn->query("SELECT * FROM $relationName");
$numCols = $result->columnCount();

echo "<table><thead><tr>";
for ($colNum = 0; $colNum < $numCols; $colNum++) {
    $colMeta = $result->getColumnMeta($colNum);
    echo "<th><code>" . $colMeta["name"] . "</code> [<code>" . $colMeta["native_type"] . "</code>]</th>";
}
echo "</tr></thead><tbody>";
foreach ($result->fetchAll() as $resultRow) {
    echo "<tr>";
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
