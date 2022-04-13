/*
    In *.hack files use double quotes instead single
    Use:
        ./bin/hack-exec "./test/Static.hack"
    in terminal
*/

class Foo
{
    public static $my_static = 'foo';

    public function staticValue() {
        return self::$my_static;
    }
}

class Bar extends Foo
{
    public function fooStatic() {
        return parent::$my_static;
    }
}


print "1:" . Foo::$my_static . "\n";

$foo = new Foo();
print "2:" . $foo->staticValue() . "\n";
print "3:" . $foo->my_static . "\n";      // Undefined "Property" my_static

print "4:" . $foo::$my_static . "\n";
$classname = 'Foo';
print "5:" . $classname::$my_static . "\n";

print "6:" . Bar::$my_static . "\n";
$bar = new Bar();
print "7:" . $bar->fooStatic() . "\n";
