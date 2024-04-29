from flask import Flask, request

app = Flask(__name__)

@app.route('/')
def index():
    return 'Servidor en línea.'

@app.route('/ledon', methods=['GET', 'POST'])
def control_on():
    print("Solicitud recibida. (LEDON)")
    return ""

@app.route('/ledoff', methods=['GET', 'POST'])
def control_off():
    print("Solicitud recibida. (LEDOFF)")
    return ""

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)