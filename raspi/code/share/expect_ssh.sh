#!/usr/bin/expect
set timeout 10
spawn ssh admin@192.168.42.3
expect "(yes/no)?" {
send "yes\r" 
}
expect "password:" {
send "passwd\r"
}
expect "UserDevice>" 
send "at+mwstatus\r"
#expect -re { Tx Power[\s]+:\s(\d+)\s\S+}
expect -re { RSSI \(dBm\)[\s]+:\s.(\d+)}

set result $expect_out(1,string)
 
send "ATA\r"
expect eof
puts "result is $result"
exit $result
