/*
    In *hack files use double quotes instead single
    Use:
        ./hack-exec "./test/class_basic.hack"
    in terminal
*/

class SimpleClass
{
    // property declaration
    public $var = "a default value \n";

    // method declaration
    public function displayVar() {
        echo $this->var;
    }
}

$simpleClass = new SimpleClass();
$simpleClass->displayVar();