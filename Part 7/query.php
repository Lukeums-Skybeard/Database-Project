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
$queries  = array(
    "SELECT M.designerID, COUNT(C.modelNumber) FROM Designer D LEFT OUTER JOIN make M ON ( D.designerID = M.designerID ) INNER JOIN contains_ C ON ( M.setID = C.setID ) GROUP BY M.designerID;",
    "SELECT AVG(leadTime) FROM Supplier S, DistributionCenter C, canOrderFrom O WHERE S.supplierID = O.supplierID AND C.centerID = O.centerID AND S.country = C.country;",
    "SELECT DISTINCT O.supplierID FROM Bedframe B, describes D, features_Feature F, canOrderFrom O, stocks S WHERE B.sku = D.sku AND D.modelNumber = F.modelNumber AND F.description = 'Claw Feet' AND O.centerID = S.centerID AND S.sku = B.sku AND O.leadTime < 7.0;",
    "SELECT COUNT(*) FROM stocks S, DistributionCenter D WHERE S.centerID = D.centerID AND D.name_ = 'Harold and His Big Ass Warehouse';",
    "SELECT DISTINCT C.setID FROM contains_ C WHERE (SELECT COUNT(DISTINCT I.sku) * C.count_ FROM Table_ I, describes D WHERE D.sku = I.sku AND D.modelNumber = C.modelNumber) >= 1 AND (SELECT COUNT(DISTINCT I.sku) * C.count_ FROM Chair I, describes D WHERE D.sku = I.sku AND D.modelNumber = C.modelNumber) > 2;"
);
$queryNum = intval($_GET["query"]) - 1;
assert($queryNum >= 0 && $queryNum <= 5, "Invalid query number!");
if ($queryNum < 5) {
    $query = $queries[$queryNum];
} else {
    $query = $_POST["userQuery"];
}
assert(preg_match("/\b(?:CREATE|ALTER|DROP|RENAME)\b/i", $query) === 0, "Query cannot contain CREATE, ALTER, DROP, or RENAME statements!");
$result  = $conn->query($query);
$numCols = $result->columnCount();

echo "<p><strong>Query:</strong> <code>" . $result->queryString . "</code></p>";
try {
    $output = "<table><thead><tr>";
    for ($colNum = 0; $colNum < $numCols; $colNum++) {
        $colMeta = $result->getColumnMeta($colNum);
        $output  = $output . "<th><code>" . $colMeta["name"] . "</code> [<code>" . $colMeta["native_type"] . "</code>]</th>";
    }
    $output = $output . "</tr></thead><tbody>";
    foreach ($result->fetchAll() as $resultRow) {
        $output = $output . "<tr>";
        for ($colNum = 0; $colNum < $numCols; $colNum++) {
            $output = $output . "<td>" . $resultRow[$colNum] . "</td>";
        }
        $output = $output . "</tr>";
    }
    $output = $output . "</tbody></table>";
    echo $output;
}
catch (PDOException $e) {
    echo "<p>Query completed.</p>";
}

$result->closeCursor();
$result = null;
$conn   = null;
	    ?>

</body>

</html>
