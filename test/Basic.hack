/*
    In *.hack files use double quotes instead single
    Use:
        ./bin/hack-exec "./test/Basic.hack"
    in terminal
*/

class Basic
{
    // property declaration
    public $var = "a default value \n";

    // method declaration
    public function displayVar() {
        echo $this->var;
    }
}

$class = new Basic();
$class->displayVar();