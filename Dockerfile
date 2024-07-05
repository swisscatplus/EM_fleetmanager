# Use an official MariaDB image as a base image
FROM mysql:latest

# Copy the SQL file containing your specific database model to the container
COPY src/glas/database/setup/schema.sql /docker-entrypoint-initdb.d/

# Expose the MariaDB default port
EXPOSE 3306
