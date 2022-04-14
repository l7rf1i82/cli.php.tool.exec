/*
    In *.hack files use double quotes instead single
    Use:
        ./bin/hack-exec "./test/Argument.hack" "" 1024 4096 Таблица Кодировка
    in terminal
*/

class Argument
{
    public static function dumpArguments($argc, $argv) {
        var_dump($argc);
        var_dump($argv);
    }
}

Argument::dumpArguments($argc, $argv);