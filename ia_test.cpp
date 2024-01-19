#include <iostream>
#include <fann.h>

int main() {
    // Criar uma rede neural
    const unsigned int num_input = 2;
    const unsigned int num_output = 1;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 3;
    const float desired_error = 0.001f;
    const unsigned int max_epochs = 100000;
    const unsigned int epochs_between_reports = 1000;

    FANN::neural_net net;
    net.create_standard(num_layers, num_input, num_neurons_hidden, num_output);

    // Configurar os parâmetros de treinamento
    net.set_activation_function_hidden(FANN::SIGMOID);
    net.set_activation_function_output(FANN::SIGMOID);
    net.set_training_algorithm(FANN::TRAIN_RPROP);

    // Criar dados de treinamento
    FANN::training_data data;
    data.set_train_data(
        FANN::array<float>(0, 0),
        FANN::array<float>(0)
    );
    data.add_train_data(
        FANN::array<float>(0, 1),
        FANN::array<float>(1)
    );
    data.add_train_data(
        FANN::array<float>(1, 0),
        FANN::array<float>(1)
    );
    data.add_train_data(
        FANN::array<float>(1, 1),
        FANN::array<float>(0)
    );

    // Treinar a rede neural
    net.train_on_data(data, max_epochs, epochs_between_reports, desired_error);

    // Testar a rede neural
    for (float i : {0, 1}) {
        for (float j : {0, 1}) {
            FANN::array<float> input = {i, j};
            FANN::array<float> output;
            net.run(input, output);
            std::cout << "Entrada: " << i << " " << j << " Saída Prevista: " << output[0] << std::endl;
        }
    }

    return 0;
}