from guizero import App, Text, Drawing

import paho.mqtt.client as mqtt

from pathlib import Path
from time import sleep

from omxplayer.player import OMXPlayer
from pathlib import Path
from time import sleep
import os.path

import threading
import argparse

class Application(threading.Thread, OMXPlayer):    

    def __init__(self, name, ip, port, ROI):
        #thread
        threading.Thread.__init__(self)
        self.name = name
        self.die = False

        #video
        self.VIDEO_PATH = Path("/home/pi/RaspiPimbal/media/file_example_MP3_5MG.mp3") 
        if os.path.isfile(self.VIDEO_PATH):
            print("it IS a file")
            #OMXPlayer.__init__(self, source = self.VIDEO_PATH, args=['--no-osd','-o','alsa:hw:1,0'])
        else:
            print("it is not a file")
        
        #application MQTT
        self.functions_dict = {"/pimbal/point":self.point,    
                      "/pimbal/stop":self.stop,
                      }
        self.client = mqtt.Client()
        self.client.connect(ip,port,60)
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.on_disconnect = self.on_disconnect
        
        #ROIs
        self.ROI = ROI

        #application 
        self.status = dict()
        self.count = 0
        self.points = 0
        
        
    def Im_here(self):
        print("I am here!")

        
        

    def get_status_mediaplayer(self):
        return self.status

    def player_handler(self):
        try: 
            print("pimbal function")
        except:
            print('repeat')
        print("let the players be players")  

    #MQTT events
    
    def on_connect(self, client, userdata, flags, rc):
      print("Connected with result code "+str(rc))
      
      for topic in self.functions_dict:
          print(topic)
          print("connect to topic: ",topic)
          self.client.subscribe(topic)
    
    def on_message(self, client, userdata, msg):
        if msg.topic in self.functions_dict:
            self.functions_dict[msg.topic](msg.payload.decode())

    def on_disconnect(self):
        print("fuck!")
    
    #functions
    def point(self, arg):
        print("POINT")
        print(arg)
        index = arg.split()[0]
        print(index)
        ROI[index][5]=1
        print(ROI[index])
        self.points+=1
        
    def run(self):
        try:
            while not self.die:
                #MQTT functions
                self.client.loop(1)
                self.count+=1
                if self.count > 65530:
                    self.count = 0
                    
                #pimbal functions
                self.player_handler()
                
        except KeyboardInterrupt:
            print('will stop the main')
            self.join()          
    
    def join(self):
        self.die = True
        print("will stop the App")
        
        super().join()
         
         
def points():
    print("points")
    
  

      
if __name__== "__main__":
    
    parser = argparse.ArgumentParser(description='Esse programa tenta uma conexão com o serviço MQTT e, quando conectado, aguarda eventos nos end-points /pimbal/point e /pimbal/stop')
    parser.add_argument('--config', type=str, help='Arquivo de configuração.', default='/home/pi/cpp_cam/config.conf')
    parser.add_argument('--ip', type=str, help='IP do serviço MQTT', default='192.168.0.104')
    parser.add_argument('--port', type=str, help='PORTA do serviço MQTT', default='1883')
    args = parser.parse_args()
    with open(args.config, 'r') as file:  # Use file to refer to the file object
        data = file.read()
        lines_of_data = data.split('\n')
        ramdisk_dir = lines_of_data[0]
        n_ROIs = lines_of_data[1]
        ROIs = []
        for l in lines_of_data[2:]:
            ROIs.append(l.split(' '))
            
    runner = Application("MainApp",ROI = ROIs, ip=args.ip, port = int(args.port))
    
    app = App("Hello world")
    # create drawing object
    d = Drawing(app, width="fill", height="fill")
    d.bg = "light blue"
    
    # drawing the shapes
    for r in ROIs:
        print(r)
        d.rectangle(r[1], r[2], r[3], r[4], color='grey')
    

    text = Text(app, text="")
    text.repeat(1000  , points)  # Schedule call to counter() every 10ms

    runner.start()
    app.display()



