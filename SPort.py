import serial.tools.list_ports
#import serial


port_list= list(serial.tools.list_ports.comports())
count_ports=0
while(count_ports<len(port_list)):

    print(str(count_ports)+" "+str(port_list[count_ports]))
    count_ports+=1


selected = int(input("Select your port "))

comand_list={"blue":"ON", "green":"GR"}

if selected>=0 and selected<len(port_list):
    arduino = serial.Serial(
    port=str((port_list[selected])[0]),
    baudrate=9600,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS)

    arduino.isOpen()
    if arduino.is_open is True:
        print("Conected to controller")
    else:
        print("Can't open conectoin to you port "+(str(port_list[selected][0])))
        exit(0)
else :
    print("Do not have this port")
    exit(0)

keys={"1","2","3","4","5","6","7","8","0"}
done=1;
while(done):
    in_key = str(input("Enter your command "))
    if (in_key in keys):
        arduino.write (str(in_key).encode("utf-8"))
        print(str(arduino.read(6)))
    elif(in_key == "exit"):
        arduino.close()
        print("Controller disconected")
        done=0
    elif(in_key=="help"):
        f=open("button_help",'r')

        print(f.read())
        f.close()
        continue
    else:
        print ("Please input correct command")
        #done=0
        continue