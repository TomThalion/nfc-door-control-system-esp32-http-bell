#ifndef PORT_H
#define PORT_H
/**
 * @brief Represents a port for a server
 * 
 * @author Tom Gaßmann
 * @version 1.0
 * 
 */
class Port {
public:
    /**
     * @brief Construct a new Port object
     * 
     * @param port new Port
     */
    Port(int port);

    /**
     * @brief Get the Port object
     * 
     * @return int port in int
     */
    int getPort();

    /**
     * @brief Set the Port object
     * 
     * @param port port in int
     */
    void setPort(int port);

private:
    int port;
};
#endif 