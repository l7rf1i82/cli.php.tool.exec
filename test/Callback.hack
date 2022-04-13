/*
    In *.hack files use double quotes instead single
    Use:
        ./bin/hack-exec "./test/Callback.hack" "Callback::main" 1024 4096
    in terminal
*/

class Callback
{
    public static function main($argc, $argv) {
        print "exec Callback::main \n";
    }
}