<!-- -*-html-*- -->
<!DOCTYPE html>
<html lang="en-US">

<head>
    <title>Fantastic Furniture</title>
</head>

<body>

    <h1>Fantastic Furniture</h1>
    <p><strong>Team GLASTA Members:</strong> Alexander Altman, Schuyler Davis, Timothy Gibson</p>

    <hr>
    <h2>Relations:</h2>

    <ul>
        <li>
            <a href="relation.php?relation=Supplier"><code>Supplier</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Designer"><code>Designer</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Set_"><code>Set_</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Model"><code>Model</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Item"><code>Item</code></a>
        </li>
        <li>
            <a href="relation.php?relation=DistributionCenter"><code>DistributionCenter</code></a>
        </li>
        <li>
            <a href="relation.php?relation=make"><code>make</code></a>
        </li>
        <li>
            <a href="relation.php?relation=contains_"><code>contains_</code></a>
        </li>
        <li>
            <a href="relation.php?relation=describes"><code>describes</code></a>
        </li>
        <li>
            <a href="relation.php?relation=canOrderFrom"><code>canOrderFrom</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Chair"><code>Chair</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Table_"><code>Table_</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Desk"><code>Desk</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Stool"><code>Stool</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Cabinet"><code>Cabinet</code></a>
        </li>
        <li>
            <a href="relation.php?relation=Bedframe"><code>Bedframe</code></a>
        </li>
        <li>
            <a href="relation.php?relation=features_Feature"><code>features_Feature</code></a>
        </li>
    </ul>

    <hr>
    <h2>Sample Queries:</h2>

    <ol>
        <li>
            <a href="query.php?query=1">&ldquo;How many models has each designer designed?&rdquo;</a>
        </li>
        <li>
            <a href="query.php?query=2">&ldquo;What is the average lead time from suppliers to distribution centers when both are in the same country?&rdquo;</a>
        </li>
        <li>
            <a href="query.php?query=3">&ldquo;Which suppliers can get me a claw-footed bedframe in less than a week?&rdquo;</a>
        </li>
        <li>
            <a href="query.php?query=4">&ldquo;How many items is my old buddy Harold stocking in that warehouse of his?&rdquo;</a>
        </li>
        <li>
            <a href="query.php?query=5">&ldquo;Which sets have more than two chairs and at least one table?&rdquo;</a>
        </li>
    </ol>

    <hr>
    <h2>Item Finder:</h2>

    <form action="finder.php" method="post">
        <p>Search for item by name or attribute:</p>
        <input type="text" name="searchText" value="" size="50">
        <br>
        <input type="submit" value="Search">
        <input type="reset" value="Clear">
    </form>

    <hr>
    <h2>Ad-hoc Query:</h2>

    <form action="query.php?query=6" method="post">
        <p>Enter Query Here:</p>
        <input type="text" name="userQuery" value="" size="100">
        <br>
        <input type="submit" value="Submit">
        <input type="reset" value="Clear">
    </form>

    <hr>

</body>

</html>
