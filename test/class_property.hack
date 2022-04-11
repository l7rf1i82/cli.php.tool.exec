/*
    In *hack files use double quotes instead single
    Use:
        ./hack-exec "./test/class_property.hack"
    in terminal
*/

class User
{
    public $id;
    public $name;

    public function __construct(int $id, ?string $name)
    {
        $this->id = $id;
        $this->name = $name;
    }
}

$user = new User(1234, "Username");

var_dump($user->id);
var_dump($user->name);