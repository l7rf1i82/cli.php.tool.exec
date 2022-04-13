/*
    In *.hack files use double quotes instead single
    Use:
        ./bin/hack-exec "./test/FieldsProperty.hack"
    in terminal
*/

class FieldsProperty
{
    public $id;
    public $name;

    public function __construct(int $id, ?string $name)
    {
        $this->id = $id;
        $this->name = $name;
    }
}

$class = new FieldsProperty(1234, "Username");

var_dump($class->id);
var_dump($class->name);