# Use the Python 3.10.14 slim image as the base
FROM python:3.10.14-slim-bookworm

# Set the working directory inside the container
WORKDIR /web

# Copy all existing files to the container
COPY . /web

# Install dependencies from requirements.txt without cache
RUN pip install --no-cache-dir -r requirements.txt

COPY . .
# Expose the port Flask will run on
EXPOSE 5000

# Set the command to run the Flask app
CMD ["python", "Test1.py"]
