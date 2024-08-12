from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def hello_world():
    return render_template('index.html', name='there')

@app.route('/User')
def user_room():
    return render_template('user.html', name='there')

if __name__ == '__main__':
    app.run(debug=True)
