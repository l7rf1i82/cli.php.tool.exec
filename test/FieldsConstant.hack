/*
    In *.hack files use double quotes instead single
    Use:
        ./bin/hack-exec "./test/FieldsConstant.hack"
    in terminal
*/

class FieldsConstant
{
    const CONSTANT = "constant value";

    function showConstant() {
        echo  self::CONSTANT . "\n";
    }
}

echo FieldsConstant::CONSTANT . "\n";

$classname = "FieldsConstant";
echo $classname::CONSTANT . "\n";

$class = new FieldsConstant();
$class->showConstant();

echo $class::CONSTANT."\n";
