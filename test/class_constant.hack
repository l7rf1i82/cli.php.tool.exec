/*
    In *hack files use double quotes instead single
    Use:
        ./hack-exec "./test/class_constant.hack"
    in terminal
*/

class MyClass
{
    const CONSTANT = "constant value";

    function showConstant() {
        echo  self::CONSTANT . "\n";
    }
}

echo MyClass::CONSTANT . "\n";

$classname = "MyClass";
echo $classname::CONSTANT . "\n";

$class = new MyClass();
$class->showConstant();

echo $class::CONSTANT."\n";
