from guizero import App, Text
import threading

class GUI(threading.Thread):
    def __init__(self,name):
        #thread
        threading.Thread.__init__(self)
        self.name = name
        self.die = False
        #application gui        

        
    def points(self):
        self.text.value = int(self.text.value) + 1

    
    
    def run(self):
        try:
            count = 0
            while not self.die:

                #GUI functions
                app = App("Hello world")
                text = Text(app, text="1")
                text.repeat(1000, self.points)  # Schedule call to counter() every 1000ms
                app.display()
                self.die = True
                
            print("not again!")

        except KeyboardInterrupt:
            print('will stop the main')
            
    
    def join(self):        
        print("will stop the GUI")
        super().join()