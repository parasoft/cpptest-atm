FROM cpptest-ct-std:latest

USER parasoft:parasoft

# install GitHub Runner
RUN mkdir actions-runner && cd actions-runner && \
    curl -o actions-runner-linux-x64-2.315.0.tar.gz -L https://github.com/actions/runner/releases/download/v2.315.0/actions-runner-linux-x64-2.315.0.tar.gz && \
    tar xzf ./actions-runner-linux-x64-2.315.0.tar.gz

# pre-configure C/C++test by creating cpptestcli.properties in $HOME directory
ARG PARASOFT_LS_URL
RUN echo "parasoft.eula.accepted=true" > cpptestcli.properties && \
    echo "cpptest.license.network.edition=server_compliance_edition" >> cpptestcli.properties && \
    echo "license.network.url=$PARASOFT_LS_URL" >> cpptestcli.properties && \
    echo "license.network.enabled=true" >> cpptestcli.properties

# > docker build -t cpptest-ct-std:runner --build-arg PARASOFT_LS_URL=$PARASOFT_LS_URL .
