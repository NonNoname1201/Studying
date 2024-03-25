<?php
function galeria($rows, $cols)
{
    $nazwa = 'obraz';
    $numer = 1;
    print("<table border='1'>");
    for ($i = 0; $i <= $rows-1; $i++) {
        print("<tr>");
        for ($j = 1; $j <= $cols; $j++) {
            if($i*$cols + $j > 10){
                $numer = ($i*$cols + $j)%10;
                if($numer == 0){
                    $numer = 10;
                }
            }
            else{
                $numer = $i*$cols + $j;
            }

            print("<td>");
            print("<img src='galeria/miniaturki/$nazwa$numer.JPG' alt='$nazwa$numer' />");
            print("</td>");
        }
        print("</tr>");
    }
    print("</table>");
}


print("<div style='background-color: #d0eefe; padding-bottom: 20px;'>");

print("<h1 align='center'>Galeria</h1>");

print("<div style='display: flex; justify-content: center; align-items: center;'>");

galeria(3, 4);

print("</div>");

print("</div>");

print("<a href='index.php'>Home</a><br><br>");
?>
