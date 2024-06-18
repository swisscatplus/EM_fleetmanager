# Use an official MariaDB image as a base image
FROM mysql:latest

# Set environment variables
ENV MYSQL_ROOT_PASSWORD=Super2019
ENV MYSQL_DATABASE=epfl
ENV MYSQL_USER=epfl
ENV MYSQL_PASSWORD=Super2019
ENV TZ=Europe/Zurich

# Copy the SQL file containing your specific database model to the container
COPY src/glas/database/sql/schema.sql /docker-entrypoint-initdb.d/

# Expose the MariaDB default port
EXPOSE 3306
