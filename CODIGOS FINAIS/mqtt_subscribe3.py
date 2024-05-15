import paho.mqtt.subscribe as subscribe
from datetime import datetime
from dateutil.relativedelta import relativedelta

def on_message_print(client, userdata, message):
  # Desconsiderar o tempo de diferença entre a hora do computador e do servidor NTP
  now = datetime.now() - relativedelta(seconds=33)
  arrival_time = now.strftime("%H:%M:%S")  # Format time (hour:minute:second)

  # Print message with arrival time
  print(f"Received at {arrival_time}: Topic: {message.topic}, Payload: {message.payload.decode('utf-8')}")

# Subscribe with callback function and userdata (optional)
subscribe.callback(on_message_print, "JESSICA/teste", hostname="test.mosquitto.org")
